set xrange [-10000:10000]
set yrange [-10000:10000]
set size square
plot "./points.dat" using 1:2 pt 7 ps 1
replot "./circle.dat" using 1:2:3 with circles
