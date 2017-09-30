<?php
echo'
		<style>
		body
			{
				background-color:black;
				color:white;
				font-family:"Palatino";
			}
		#receipt
			{
				background:url(scroll.jpg);
				background-repeat:no-repeat;
				color:black;
				background-size: 1300px 1500px;
				
				
			}
		</style>
	';
echo '	
	<body>
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
		<br>';
	//connection 
	$con=mysql_connect("localhost","root","");
	if($con)
	{
		//database selection
		$temp=mysql_select_db("library",$con);
		if($temp)
		{
			$date=date('y-m-d');
			//query to insert into feedback table the form details

			$sql="Insert into guest_feedback values('".$_POST['fname']."','".$_POST['mname']."','".$_POST['lname']."','";
			$sql=$sql.$_POST['sex']."','".$_POST['cnum']."','".$_POST['emailid']."','".$_POST['exp']."','".$_POST['staff']."','".$_POST['cleanliness']."','".$_POST['ventilation'];
			$sql=$sql."','".$_POST['effeciency']."','".$_POST['facility']."','".$_POST['qty']."','".$_POST['suff']."','".$_POST['updateness']."','".$_POST['condn']."','".$_POST['variety'];
			$sql=$sql."','".$_POST['overallrate']."','".$_POST['src']."','".$_POST['recc']."','".$_POST['suggestion']."','$date')";
			$result=mysql_query($sql);
		}
		else 
			echo '<br>Database selection Unsuccessful';
	}
	
	else 
	    echo 'Connection Unsuccessful';

echo 	'</body>';
?>