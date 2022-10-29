import pyautogui
import keyboard
import time

scW, scY	= pyautogui.size()
X			= scW / 2
Y			= scY / 2
stepX		= 16
stepY		= 16

def downArrow():
	pyautogui.moveTo(X - stepX, Y - stepY)
	pyautogui.mouseDown()
	pyautogui.moveTo(X - stepX / 2, Y) 
	pyautogui.moveTo(X, Y + stepY)
	pyautogui.moveTo(X + stepX / 2, Y)
	pyautogui.moveTo(X + stepX, Y - stepY)
	pyautogui.mouseUp()

def upArrow():
	pyautogui.moveTo(X - stepX, Y + stepY)
	pyautogui.mouseDown()
	pyautogui.moveTo(X - stepX / 2, Y) 
	pyautogui.moveTo(X, Y - stepY)
	pyautogui.moveTo(X + stepX / 2, Y)
	pyautogui.moveTo(X + stepX, Y + stepY)
	pyautogui.mouseUp()

def horizontalLine():
	pyautogui.moveTo(X - stepX * 2, Y)
	pyautogui.mouseDown()
	pyautogui.moveTo(X - stepX, Y)
	pyautogui.moveTo(X + stepX, Y)
	pyautogui.moveTo(X + stepX * 2, Y)
	pyautogui.mouseUp()

def verticalLine():
	pyautogui.moveTo(X, Y + stepY * 2)
	pyautogui.mouseDown()
	pyautogui.moveTo(X, Y + stepY)
	pyautogui.moveTo(X, Y - stepY)	
	pyautogui.moveTo(X, Y - stepY * 2)
	pyautogui.mouseUp()

print("ready")
while True:
	if keyboard.is_pressed('i'):
		upArrow()
	if keyboard.is_pressed('k'):
		downArrow()
	if keyboard.is_pressed('u'):
		verticalLine()
	if keyboard.is_pressed('j'):
		horizontalLine()
	if keyboard.is_pressed('o'):
		upArrow()
		downArrow()
		verticalLine()
		horizontalLine()
	if keyboard.is_pressed('p'):
		break
	time.sleep(0.1)