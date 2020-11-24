<?php
   	include("connect.php");
   	
   	$link=Connection();

	$Account=$_POST["Account"];
	$Message=$_POST["Message"];

	$query = "INSERT INTO `boarduser` (`Account`, `Message`) 
		VALUES ('".$Account."','".$Message."')"; 
   	
   	mysql_query($query,$link);
	mysql_close($link);

   	header("Location: 1.php");
?>
