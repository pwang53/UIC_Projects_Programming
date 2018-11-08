#draw on a picture
#PQ
# 9/19/17

#set function of stars    
def drawStar(t):
  turn(t,344)
  t.setPenWidth(2)
  t.setPenColor(yellow)
  loop = 0
  while (loop<5):
   forward(t,50)
   turn(t,144)
   loop = loop + 1
  turn(t,16)
  
#set function of rentangles
def drawRentangle(t,num,redRGB,greenRGB,blueRGB):
  color = makeColor(redRGB,greenRGB,blueRGB)
  t.setPenColor(color)
  t.setPenWidth(5)
  forward(t,10*num)
  turnRight(t)
  forward(t,25*num)
  turnRight(t)
  forward(t,10*num)
  turnRight(t)
  forward(t,25*num)
  turnRight(t)

#set function of hexagons
def drawHexagon(t,num,redRGB,greenRGB,blueRGB):
  turn(t,30)
  color = makeColor(redRGB,greenRGB,blueRGB)
  t.setPenColor(color)
  t.setPenWidth(5)
  loop = 0
  while(loop < 7):
    turn(t,60)
    forward(t,10*num)
    loop = loop + 1
  turn(t,30)

#set function of triangels  
def drawTriangle(t,color):
  t.setPenColor(color)
  t.setPenWidth(5)
  turn(t,30)
  forward(t,90)
  turn(t,120)
  forward(t,90)
  turn(t,120)
  forward(t,90)
  turn(t,90)

#set function of lines  
def drawLine(t,color):
  t.setPenColor(color)
  t.setPenWidth(2)
  forward(t,30)

#set function of squares
def drawSquare(t,color):
  turn(t,315)
  t.setPenColor(color)
  t.setPenWidth(5)
  forward(t,80)
  turnRight(t)
  forward(t,80)
  turnRight(t)
  forward(t,80)
  turnRight(t)
  forward(t,80)
  turnRight(t)
  turn(t,45)
  
#use file picker to choose a file
fname = pickAFile()
print(fname)

#pass filename to a picture object
pic = makePicture(fname)

#make a turtle, pass in picture
t1 = makeTurtle(pic)
t2 = makeTurtle(pic)
t3 = makeTurtle(pic)
t4 = makeTurtle(pic)
t5 = makeTurtle(pic)
t6 = makeTurtle(pic)

#draw Stars
penUp(t1)
moveTo(t1,200,250)
penDown(t1)
drawStar(t1)
penUp(t1)
moveTo(t1,460,250)
penDown(t1)
drawStar(t1)
penUp(t1)
moveTo(t1,250,170)
penDown(t1)
drawStar(t1)
penUp(t1)
moveTo(t1,410,170)
penDown(t1)
drawStar(t1)
penUp(t1)
moveTo(t1,300,130)
penDown(t1)
drawStar(t1)
penUp(t1)
moveTo(t1,360,130)
penDown(t1)
drawStar(t1)

#Draw Rentangles
penUp(t2)
moveTo(t2,180,400)
penDown(t2)
drawRentangle(t2,12,255,115,0)
penUp(t2)
moveTo(t2,230,280)
penDown(t2)
drawRentangle(t2,8,155,0,155)
penUp(t2)
moveTo(t2,280,200)
penDown(t2)
drawRentangle(t2,4,255,0,255)

#Draw Hexagons
penUp(t3)
moveTo(t3,295,163)
penDown(t3)
drawHexagon(t3,2,0,255,255)
penUp(t3)
moveTo(t3,374,180)
penDown(t3)
drawHexagon(t3,2,0,255,255)

#Draw Triangles
penUp(t4)
moveTo(t4,230,280)
penDown(t4)
drawTriangle(t4,red)
penUp(t4)
moveTo(t4,340,280)
penDown(t4)
drawTriangle(t4,red)

#Draw Lines
penUp(t5)
moveTo(t5,200,280)
penDown(t5)
drawLine(t5,green)
penUp(t5)
moveTo(t5,460,280)
penDown(t5)
drawLine(t5,green)
penUp(t5)
moveTo(t5,250,200)
penDown(t5)
drawLine(t5,green)
penUp(t5)
moveTo(t5,410,200)
penDown(t5)
drawLine(t5,green)
penUp(t5)
moveTo(t5,300,160)
penDown(t5)
drawLine(t5,green)
penUp(t5)
moveTo(t5,360,160)
penDown(t5)
drawLine(t5,green)

#draw Squares
penUp(t6)
moveTo(t6,260,400)
penDown(t6)
drawSquare(t6,blue)
penUp(t6)
moveTo(t6,400,400)
penDown(t6)
drawSquare(t6,blue)

#show picture
pic.show()

savefile = pickAFile()
pic.write(savefile)
