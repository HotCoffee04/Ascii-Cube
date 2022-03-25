typedef struct Point{

    float x,y,z;

}Point;

typedef struct Line{

    Point points[2];

}Line;

void drawPoint(Point p);
void drawLine(Line l);

Point rotatePoint(Point p);

int chatToDistance(char c);


