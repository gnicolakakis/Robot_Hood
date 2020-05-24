from selenium import webdriver  # Import selenium web driver
import os
import random

driver = webdriver.PhantomJS()  # PhantomJs webdriver

driver.get('http://192.168.4.1/jpg')

num = random.randint(11111,999999)

driver.save_screenshot('screen.png')
os.rename('screen.png', str(num)+'.png')








#pip install phantomjs
#pip install selenium
#python 3.8 and python 3.8.2

#D:\PhantomJs\bin\phantomjs +add to path

#download from: https://phantomjs.org/download.html
#from downloaded folder, move from folder "bin" the executable file in main folder phantomjs
#in cmd: phantomjs to check that is in path
#SIGNOUT-SIGNIN to apply the path added folder
