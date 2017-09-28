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
		
	$lname=$_POST['lname'];
	$lpasswd=$_POST['lpasswd'];
	//connection 
	$con=mysql_connect("localhost","root","");
	if($con)
	{
		//database selection
		$temp=mysql_select_db("library",$con);
		if($temp)
		{
			//query to check login details
			$sql='select * from librarian';
			$result=mysql_query($sql);
			$row=mysql_fetch_array($result);
			if($row["username"]==$lname&&$row["password"]==sha1($lpasswd))
				echo '<br><br><br><br><br><br>
			<p align="center"><b>LOGIN SUCCESSFUL<br>WELCOME MISS '.$lname.'
			<br><br><br><br><br><br><br><br><br><br>
			<a href="lib1.html" style="text-decoration:none;color:white;
					font-family:castellar; 
					font-size:30px;">PROCEED TO MENU PAGE>></a>
			';
			else	
				echo '<br><br><br><br><br><br>
			<p align="center"><b>Oops!! Invalid Username Or Password <br> Please try again!
			<br><br><br><br><br><br><br><br><br><br>
			<a href="page1.html" style="text-decoration:none;color:white;
					font-family:castellar; 
					font-size:30px;">GO BACK<< </a>
			';
		}
		else 
			echo '<br>Database selection Unsuccessful';
	}
	
	else 
	    echo 'Connection Unsuccessful';
	
	echo '</body>'
	
?>