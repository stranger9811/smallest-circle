bif="bck.jpg"
import pygame , sys
from pygame.locals import *
import subprocess
import os

pygame.init()
screen=pygame.display.set_mode((1640,1360),0,32)
background=pygame.image.load(bif).convert()

point_color = (0,0,255)
circle_color =(255,153,51)

center=[]
points=[]
s=0
val1=0
val2=0
val3=0
while 1:
	flag=0
	for event in pygame.event.get():
		if event.type == QUIT:
			pygame.quit()
			sys.exit()
		if event.type == MOUSEBUTTONDOWN:
			flag=1		
			points.append(event.pos)

	#if len(points)>1:
		#pygame.draw.lines(screen,)
	screen.blit(background, (0,0))                                #Copy Background image to screen
	f=open('input.dat','w')
	f.write(str(len(points))+"\n")
	for point in points:                                          #Draw all Clicked points on screen
		f.write(str(point[0])+" "+str(point[1])+"\n")
		pygame.draw.circle(screen,point_color,point,5,0)

                         # C code will help to find minimum enclosing circle
	if flag==1 and len(points)>=2:
		flag=2
	if len(points)>2 and flag==2:
		os.system('bash script.sh')
		f=open('circle.dat','r')
		for line in f.xreadlines():
			line=line.split(" ")
		center=[]
		print line
		val1=line[0].split(".")[0]
		val2=line[1].split(".")[0]
		val3=line[2].split(".")[0]
		center.append(int(val1))
		center.append(int(val2))
		print center
		s=1;
	if s==1:	
		pygame.draw.circle(screen,circle_color,center,int(val3),10)
	pygame.display.update()
	
