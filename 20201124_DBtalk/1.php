<?php

	include("connect.php"); 	
	
	$link=Connection();

	$result=mysql_query("SELECT * FROM `boarduser` ORDER BY `Time` DESC",$link);
?>

<html>
   <head>
      <title>資料庫留言板</title>
   </head>
<body>
   <h1>留言板</h1>

   <table border="1" cellspacing="1" cellpadding="1">
		<tr>
			<td>&nbsp;Timestamp&nbsp;</td>
			<td>&nbsp;帳號&nbsp;</td>
			<td>&nbsp;訊息&nbsp;</td>
		</tr>
		
      <?php 
		  if($result!==FALSE){
		     while($row = mysql_fetch_array($result)) {
		        printf("<tr><td> &nbsp;%s </td><td> &nbsp;%s&nbsp; </td><td> &nbsp;%s&nbsp; </td></tr>", 
		           $row["Time"], $row["Account"], $row["Message"]);
		     }
		     mysql_free_result($result);
			 mysql_close();
			// header('Location: 2.php');
		  }
      ?>
   </table>
   <form method="post" action="2.php">
			Please input your name：
		<input type="text" name="Account" size="10"><br>
			I say：
		<input type="text" name="Message" size="10"><br>
		<input type="submit" value="傳送訊息">
	</form>
	<form method="post" action="2.php">
		<input type="submit" value="查看完整聊天內容">
	</form>
	<!-- <form method="post" action="2.php">
		<input type="submit" value="刪除資料">
	</form> -->
	<form method="post" action="2.php">
			查詢哪一位使用者之訊息：
			<input type="text" name="Account" size="10"><br>
		<input type="submit" value="查詢">
	</form>
  </body>
</html>
</body>
</html>
