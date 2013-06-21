set xrange [-300:300]
set yrange [-300:300]
set size square
plot "./points.dat" using 1:2 pt 7 ps 1
replot "./circle.dat" using 1:2:3 with circles
