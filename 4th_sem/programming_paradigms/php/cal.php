<!DOCTYPE html>
<html>
<body>

<?php
$x=$_POST[“n1”];
$y=$_POST[“n2”];
global $z;

switch($_POST[“op”]){

case “+”:
$z=$x+$y;
echo “$x + $y = ” . $z;
break;

case “-“:
$z=$x-$y;
echo “$x – $y = ” . $z;
break;

case “*”:
$z=$x*$y;
echo “$x * $y = ” . $z;
break;

case “/”:
$z=$x/$y;
echo “$x / $y = ” . $z;
break;

case “=”:
if ($x==$y){
echo “Yes They are equal -_- Plz Enter A Valid Operator -_-“;
}
else
echo “No They are not equal -_- Plz Enter A Valid Operator -_-“;
break;

default:
echo “Plz Enter a valid operator”;
}
?>

</body>
</html>

