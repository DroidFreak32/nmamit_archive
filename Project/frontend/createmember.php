<?php
echo'
		<style>
		body
			{
				background-color:black;
				color:black;
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
	$con=mysqli_connect("localhost","root","");
	if($con)
	{
		//database selection
		$temp=mysqli_select_db($con,"library");
		if($temp)
		{
			$date=date('y-m-d');
			$sql='Select * from temp_member';
			$result=mysqli_query($con,$sql);
			while($row=mysqli_fetch_array($result))
			{
				if(strcmp($row['Membership_no'],$_POST['mno'])==0)
					break;
			}
			$sql="Insert into Member values('".$row['Membership_no']."','".$row['Fname']."','".$row['Mname']."','".$row['Lname']."','";
			$sql=$sql.$row['Sex']."','".$row['Aadhar_no']."','".$row['Birth_Date']."','".$row['Address_line1']."','".$row['Address_line2']."','".$row['City']."','".$row['Pincode']."','".$row['State']."','".$row['Country']."','".$row['ContactNo1']."','".$row['ContactNo2']."','".$row['EmailId']."','$date')";
			$result=mysqli_query($con,$sql);
			$sql="Delete from temp_member where Membership_no='".$_POST['mno']."'";
			$result=mysqli_query($con,$sql);
			$sql="Insert into member_login values('".$_POST['mno']."','".sha1($_POST['mno'])."')";
			$result=mysqli_query($con,$sql);
			echo'
				<div id="receipt">
				<br>
				<br>
				<br>
				<br>
				<br>
				<br>
				<br>
				<br>
				<br>
				<br>
				<br>
				<br>
				<br>
				<br>
				<br>
				<br>
				<br>
				<br>
				<br>
				<br>
				<br>
					<table align="center" >
						<tr>					
							<td>&nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbspMEMBERSHIP NO</td>
							<td>&nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp
							&nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp </td>
							<td>'.$row['Membership_no'].'</td>					
							
						</tr>
						<tr>
							<td>&nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbspFIRST NAME</td>
							<td></td>
							<td>'.$row['Fname'].'</td>
						</tr>
						<tr>
							<td>&nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbspMIDDLE NAME</td>
							<td></td>
							<td>'.$row['Mname'].'</td>
						</tr>
						<tr>
							<td>&nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbspLAST NAME</td>
							<td></td>
							<td>'.$row['Lname'].'</td>
						</tr>
						<tr>
							<td>&nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbspSEX</td>
							<td></td>
							<td>'.$row['Sex'].'</td>
						</tr>
						<tr>
							<td>&nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbspAADHAR CARD NUMBER</td>
							<td></td>
							<td>'.$row['Aadhar_no'].'</td>
						</tr>
						<tr>
							<td>&nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbspBIRTH DATE</td>
							<td></td>
							<td>'.$row['Birth_Date'].'</td>
						</tr>
						<tr>
							<td>&nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbspADDRESS LINE 1</td>
							<td></td>
							<td>'.$row['Address_line1'].'</td>
						</tr>
						<tr>
							<td>&nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbspADDRESS LINE 2</td>
							<td></td>
							<td>'.$row['Address_line2'].'</td>
						</tr>
						<tr>
							<td>&nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbspCITY</td>
							<td></td>
							<td>'.$row['City'].'</td>
						</tr>
						<tr>
							<td>&nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbspPINCODE</td>
							<td></td>
							<td>'.$row['Pincode'].'</td>
						</tr>
						<tr>
							<td>&nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbspSTATE</td>
							<td></td>
							<td>'.$row['State'].'</td>
						</tr>
						<tr>
							<td>&nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbspCOUNTRY</td>
							<td></td>
							<td>'.$row['Country'].'</td>
						</tr>
						<tr>
							<td>&nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbspCONTACT NUMBER 1</td>
							<td></td>
							<td>'.$row['ContactNo1'].'</td>
						</tr>
						<tr>
							<td>&nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbspCONTACT NUMBER 2</td>
							<td></td>
							<td>'.$row['ContactNo2'].'</td>
						</tr>
						<tr>
							<td>&nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbspEMAIL ID</td>
							<td></td>
							<td>'.$row['EmailId'].'</td>
						</tr>
						<tr>
							<td>&nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbspUSERNAME</td>
							<td></td>
							<td>'.$row['Membership_no'].'</td>
						</tr><tr>
							<td>&nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbspPASSWORD</td>
							<td></td>
							<td>'.$row['Membership_no'].'</td>
						</tr>
					</table>
					<br>
				<br>
				<br>
				<br>
				<br>
				</div>
				<br>
				<br>
				<br>
				&nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp
				&nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp &nbsp
				<a href="#" style="color:white;text-decoration:none" onclick="window.print();return false;" title="Click to print this page">
				<img src="printer.jpg" height="50px" width=50px">&nbsp &nbsp Click to print this page</a>';
		}	
		else 
			echo '<br>Database selection Unsuccessful';
	}
	
	else 
	    echo 'Connection Unsuccessful';

echo 	'</body>';
?>
