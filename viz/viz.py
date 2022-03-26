from graphics import *
from settings import *



def load_background_image():
	cwd = os.path.dirname(os.path.realpath(__file__))
	return Image(Point(0,0), f'{cwd}/{BG_IMAGE}')


if __name__ == '__main__':

	backgroundImage = load_background_image()

	WIDTH = backgroundImage.getWidth()
	HEIGHT = backgroundImage.getHeight()
	backgroundImage.move(WIDTH/2, HEIGHT/2)
	
	window = GraphWin("Lem-in Visualizer", WIDTH, HEIGHT)
	backgroundImage.draw(window)

	print(sys.stdin.read())

	window.getMouse()
	window.close()
	