class star
{
	public:
        double x;
		double y;
		void move()
		{
			y--;
		}
		void show()
		{
			glPointSize(2);
			glColor3f(0,0,1);
			glBegin(GL_POINTS);
			glVertex2f(x,y);
			glEnd();
		}
};
