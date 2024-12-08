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
	win = GraphWin('Lem-in Visualizer', w, h*.8)
	win.master.geometry(f'{w}x{h}+0+0') # Set the window to open at the top left corner
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
	if text_data == "ERROR\n":
		return -1, -1, -1, -1
	iter_node, iter_edge, iter_path = itertools.tee(text_data.splitlines(), 3)
	ants = next(iter_node)
	nodes = process_nodes([line for line in iter_node if line if '-' not in line])
	edges = [line for line in iter_edge if line if 'L' not in line if '-' in line]
	paths = [line for line in iter_path if line if 'L' in line]
	return nodes, edges, paths, int(ants)

def map_range(s, a1, a2, b1, b2):
	if a1 >= a2:
		a2 = a1 + 1
	t = b1 + ((s - a1) * (b2 - b1)) / (a2 - a1)
	return t

def translate_position(circles):
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
	min_w = min_h = CIR_SIZE * 1.25
	max_w = WIDTH - CIR_SIZE * 1.25
	max_h = HEIGHT - CIR_SIZE * 1.25
	new_circles = []
	for idx, items in enumerate(circles):
		cir, name, center = items
		x = map_range(int(center.x), min_x, max_x, min_w, max_w)
		y = map_range(int(center.y), min_y, max_y, min_h, max_h)
		center = Point(x, y)
		cir = Circle(center, CIR_SIZE)
		if idx == 0: #FIRST
			cir.setFill(CIR_COLOR_F)
		elif items == circles[-1]: #LAST
			cir.setFill(CIR_COLOR_L)
		else:
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
		point1 = None
		point2 = None
		for _, name, center in circles:
			if edge[0] in name and not point1:
				point1 = center
			elif edge[1] in name and not point2:
				point2 = center
		line = Line(point1, point2)
		line.setOutline('white')
		line.setWidth(5)
		line.draw(win)
	for cir, _, __ in circles:
		cir.draw(win)
	return circles

def	animate_ants(circles, turn, ants):
	new_center = []
	old_center = []
	for who, to in turn:
		old_center.append(ants[who - 1].getAnchor())
		for _, name, center in circles:
			if to in name:
				new_center.append(center)
				break
	for _ in range(ANIM_ITER):
		for i, v in enumerate(turn):
			who, _ = v
			dx = (new_center[i].x - old_center[i].x) / ANIM_ITER
			dy = (new_center[i].y - old_center[i].y) / ANIM_ITER
			ants[who - 1].move(dx, dy)
	time.sleep(PAUSE)

def load_ant_image():
	cwd = os.path.dirname(os.path.realpath(__file__))
	return Image(Point(0,0), f'{cwd}/ant.gif')

def	run_ants(circles, paths, n_ants):
	ant_image = load_ant_image()
	ant_image.move(circles[0][2].x, circles[0][2].y)
	ants = []
	for i in range(n_ants):
		ants.append(ant_image.clone())
	for a in ants:
		a.draw(win)
	for i, movements in enumerate(paths):
		round = movements.split()
		turn = []
		for move in round:
			single = move.split('-')
			who = single[0].replace('L','')
			to = single[1]
			turn.append(tuple((int(who), to)))
		animate_ants(circles, turn, ants)

def key_pressed(key):
	if key.keysym == 'Escape':
		win.close()
		exit()

win.bind_all('<Key>', key_pressed)

if __name__ == '__main__':
	nodes, edges, paths, ants  = get_data_from_stdin()
	if nodes != -1:
		circles = draw_graph(nodes, edges)
		run_ants(circles, paths, ants)
		win.getMouse()
	else:
		print("ERROR")

	win.close()

