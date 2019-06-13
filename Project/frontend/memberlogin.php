<?php
echo 	'<style>
			body
			{
				background-color:black;
				color:white;
				font-family:castellar;
			}
		</style>';
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
		
	$mname=$_POST['mname'];
	$mpasswd=$_POST['mpasswd'];
	//connection 
	$con=mysqli_connect("localhost","root","");
	if($con)
	{
		//database selection
		$temp=mysqli_select_db($con,"library");
		if($temp)
		{
			//query to check login details
			$sql='select * from member_login';
			$result=mysqli_query($con,$sql);
			while($row=mysqli_fetch_array($result))
			if($row["Membership_No"]==$mname&&$row["Password"]==sha1($mpasswd))
			{
				$sql="Select Fname,Mname,Lname from member m,member_login ml where m.Membership_no='".$mname."'";
				$result=mysqli_query($con,$sql);
				$row=mysqli_fetch_array($result);
				echo '<br><br><br><br><br><br>
			<p align="center"><b>LOGIN SUCCESSFUL<br>WELCOME MISS '.$row['Fname'].' '.$row['Mname'].' '.$row['Lname'].'
			<br><br><br><br><br><br><br><br><br><br>
			<a href="lib1.html" style="text-decoration:none;color:white;
					font-family:castellar; 
					font-size:30px;">PROCEED>></a>
			';
			break;
			}
		/*	else	
				echo '<br><br><br><br><br><br>
			<p align="center"><b>Oops!! Invalid Username Or Password <br> Please try again!
			<br><br><br><br><br><br><br><br><br><br>
			<a href="page1.html" style="text-decoration:none;color:white;
					font-family:castellar; 
					font-size:30px;">GO BACK<< </a>
			';*/
		}
		else 
			echo '<br>Database selection Unsuccessful';
	}
	
	else 
	    echo 'Connection Unsuccessful';
	
	echo '</body>'
	
?>