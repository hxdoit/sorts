<?php
function qs(&$arr, $start, $end) {
    if ($start >= $end) {
        return;
    }
    $flag = $arr[$start];
    $i = $start + 1;
    $j = $end;
    while ($i < $j) {
        while ($i < $end && $arr[$i] <= $flag) {
            $i++;
        }
        while ($j > $start && $arr[$j] >= $flag) {
            $j--;
        }
        if ($i < $j) {
            $temp = $arr[$i];
            $arr[$i] = $arr[$j];
            $arr[$j] = $temp;
        }
    }
    if ($flag > $arr[$j])
    {
        $temp = $arr[$j];
        $arr[$j] = $flag;
        $arr[$start] = $temp;
    }
    qs($arr, $start, $j - 1);
    qs($arr, $j + 1, $end);
    
}
$arr = [];
$i=0;
while ($i < 1000) {
    $arr[] = rand(0,1000000);
    $i++;
}
qs($arr, 0, count($arr) - 1);
$i = 0;
while ($i < 999) {
    if ($arr[$i] > $arr[$i+1]) {
        var_dump($i);
    }
    $i++;
}

