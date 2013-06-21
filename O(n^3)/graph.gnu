set xrange [-400:400]
set yrange [-400:400]
set size square
plot "./points.dat" using 1:2 pt 7 ps 1
replot "./circle.dat" using 1:2:3 with circles
