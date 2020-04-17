public static class Point{
	private int x;
	private int y;

	public Point(int x, int y){
		this.x = x;
		this. y = y;
	}

	public int getX(){
		return x;
	}

	public int getY(){
		return y;
	}

	public double getDistance(Point otherPoint){
		return Math.sqrt(Math.pow(otherPoint.x -x, 2) 
			+ Math.pow(otherPoint.y -y), 2);
	}

	public boolean isWithinDistance(Point otherPoint, double distance){
		if(Math.abs(otherPoint.x - x) <distance || (otherPoint.y -y) > distance){
				return false;
		}

		return getDistance(otherPoint <=distance);
	}

	public static List<Point> getPointsWithinDistance(List<Point> list, Point point,
		double distance){
		List<Point> withinDistanceList = new ArrayList<Point>();
		for(Point p : list){
			if(p.isWithinDistance(point, distance)){
				withinDistanceList.add(p);
			}
		}

		System.our.println(String.format("Points within %s of point x = %s, y = %s", 
			distance, point.getX(), point.getY()));
		for(Point p : withinDistanceList){
			System.out.println(String.format("Point: x = %s, y = %s", p.getX(), p.getY()));

		}
		return withinDistanceList;
	}
}