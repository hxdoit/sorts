<?php
$i=0;
$fw = fopen("/tmp/a.txt",'w');
while($i<$argv[1])
{
 fwrite($fw,rand(0,100*$argv[1])."\n"); 

  ++$i;
}
fclose($fw);
