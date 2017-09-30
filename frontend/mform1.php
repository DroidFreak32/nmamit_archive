<?php
	echo 	'<style>
			body
			{
				background-color:black;
				color:white;
				font-family:castellar;
			}
			span
			{
				visibility:hidden; 
				color:red;
			}
		</style>';
	echo 	'
			<script>
			function validate()
			{
				var myform=document.project;
				//TO VALIDATE USERNAME
				if ((!(isNaN(myform.uname.value)))&&(myform.uname.value!=""))//TO CHECK IF THE NAME IS A NUMBER
				{
						document.getElementById("errorUname").style.visibility="visible";
						document.getElementById("Uname").style.border="2px solid #F00";
						return false;
                }
				else
				{
					document.getElementById("errorUname").style.visibility="hidden";
					document.getElementById("Uname").style.border="1px solid black";
				}
				if(myform.password.value!=myform.temp_passwd.value)
				{
					document.getElementById("errorPasswd").style.visibility="visible";
						document.getElementById("Temp_passwd").style.border="2px solid #F00";
						return false;
				}
				else
				{
					document.getElementById("errorPasswd").style.visibility="hidden";
					document.getElementById("Temp_passwd").style.border="1px solid black";
				}
				return true;
			}
			</script>
			';
	echo    '<body>
			<!--HEADER WITH LOGO-->
		<div style="top:0px" >
			<img src="logo.png" height="150" width="200" style="float:left">
			<img src="logo.png" height="150" width="200" style="float:right">
			<div style="color:white;
					text-align:center;
					font-family:castellar; 
					font-size:60px;
					padding-top:40px;
					text-shadow: 1px 1px 2px white, 0 0 2px white, 0 0 5px white;" >
				<u>HOGWARTS LIBRARY</u>
			</div>
		<br>
		<br>
		<br>
		<br>
		<br>
		<br>';
	
	//see if wrks without connection 
	
	//connection 
	$con=mysql_connect("localhost","root","");
	if($con)
	{
		//database selection
		$temp=mysql_select_db("library",$con);
		if($temp)
		{
			//GENERATES RANDDOM MEMBERSHIP NUMBER(10 DIGIT LONG)
	a:		for ($randomNumber = mt_rand(1, 9), $i = 1; $i < 10; $i++) 
				$randomNumber .= mt_rand(0, 9);
			$m_id="LIB".$randomNumber;
			$sql="select * from temp_member";
			$result=mysql_query($sql);
			while($row=mysql_fetch_array($result))//To check if the id is already previously assigned to a member or not
				if($row['Membership_No']==$m_id)
					goto a;
			//query to insert into temp table the form details
			$sql="Insert into temp_member values('$m_id','".$_POST['mfname']."','".$_POST['mmname']."','".$_POST['mlname']."','";
			$sql=$sql.$_POST['sex']."','".$_POST['aadhar_no']."','".$_POST['bdate']."','".$_POST['addl1']."','".$_POST['addl2']."','".$_POST['city']."','".$_POST['pincode']."','".$_POST['state']."','".$_POST['country']."','".$_POST['cnum1']."','".$_POST['cnum2']."','".$_POST['emailid']."')";
			$result=mysql_query($sql);
		}
		else 
			echo '<br>Database selection Unsuccessful';
	}
	
	else 
	    echo 'Connection Unsuccessful';
	
	
	echo'THANK YOU!! YOU ARE JUST A STEP AWAY FROM BECOMING A LIFETIME MEMBER OF THE HOGWARTS LIBRARY. KINDLY PAY THE MEMBERSHIP FEE AND PROCEED
	     TO THE LIBRARIAN TO CONFIRM YOUR MEMBERSHIP. WE HOPE TO SERVE YOU IN THE BEST WAY POSSIBLE';
		
    echo 'YOUR MEMBERSHIP NUMBER ALLOTED IS :'.$m_id;	
	echo '</body>'
?>