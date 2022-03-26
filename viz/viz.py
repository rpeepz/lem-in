import itertools
from graphics import *
from settings import *

def load_background_image():
	cwd = os.path.dirname(os.path.realpath(__file__))
	return Image(Point(0,0), f'{cwd}/{BG_IMAGE}')

def draw_main_window():
	bg_image = load_background_image()
	w = bg_image.getWidth()
	h = bg_image.getHeight()
	bg_image.move(w / 2, h / 2)
	win = GraphWin('Lem-in Visualizer', w, h)
	bg_image.draw(win)
	return win

win = draw_main_window()
WIDTH = win.getWidth()
HEIGHT = win.getHeight()

def process_nodes(node_list):
	nodes = []
	if len(node_list) > MAX_NODES:
		print('ERROR: Unable to visualize: Too many nodes')
		win.close()
		exit()
	iter_node = iter(node_list)
	for line in iter_node:
		if '##start' in line:
			start = next(iter_node)
		elif '##end' in line:
			end = next(iter_node)
		else:
			nodes.append(tuple(line.split()))
	nodes.insert(0, tuple(start.split()))
	nodes.append(tuple(end.split()))
	return nodes

def get_data_from_stdin():
	text_data = sys.stdin.read()
	iter_node, iter_edge, iter_path = itertools.tee(text_data.splitlines(), 3)
	next(iter_node)
	nodes = process_nodes([line for line in iter_node if line if '-' not in line])
	edges = [line for line in iter_edge if line if 'L' not in line if '-' in line]
	paths = [line for line in iter_path if line if 'L' in line]
	return nodes, edges, paths

def map_range(s, a1, a2, b1, b2):
	if a1 >= a2:
		a2 = a1 + 1
	t = b1 + ((s - a1) * (b2 - b1)) / (a2 - a1)
	return t

def translate_position(circles):
	'''set input limits'''
	max_x = max_y = 0
	min_x = min_y = 10000
	for _, __, center in circles:
		x = int(center.x)
		y = int(center.y)
		if x > max_x:
			max_x = x
		if x < min_x:
			min_x = x
		if y > max_y:
			max_y = y
		if y < min_y:
			min_y = y
	'''set range limts'''
	min_w = min_h = CIR_SIZE * 1.25
	max_w = WIDTH - CIR_SIZE * 1.25
	max_h = HEIGHT - CIR_SIZE * 1.25
	new_circles = []
	for cir, name, center in circles:
		x = map_range(int(center.x), min_x, max_x, min_w, max_w)
		y = map_range(int(center.y), min_y, max_y, min_h, max_h)
		center = Point(x, y)
		cir = Circle(center, CIR_SIZE)
		cir.setFill(CIR_COLOR)
		new_circles.append(tuple((cir, name, center)))
	return new_circles

def draw_graph(nodes, edges):
	circles = []
	for name, x, y in nodes:
		x = int(x)
		y = int(y)
		center = Point(x, y)
		cir = Circle(center, CIR_SIZE)
		cir.setFill(CIR_COLOR)
		circles.append(tuple((cir, name, center)))
	circles = translate_position(circles)
	for edge in edges:
		edge = edge.split('-')
		for _, name, center in circles:
			if edge[0] in name:
				point1 = center
			elif edge[1] in name:
				point2 = center
		line = Line(point1, point2)
		line.setOutline('white')
		line.setWidth(5)
		line.draw(win)
	for cir, _, __ in circles:
		cir.draw(win)

if __name__ == '__main__':
	nodes, edges, paths  = get_data_from_stdin()
#	print(paths)

	draw_graph(nodes, edges)
	win.getMouse()
	win.close()

