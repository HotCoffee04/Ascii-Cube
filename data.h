/*
    The shape to draw:
    (Could be implemented a load from file function)
    (and multiple shapes to draw... maybe one day...) 
*/

    Point point1;
    point1.x = 10;
    point1.y = 10;
    point1.z = 10;

    Point point2;
    point2.x = 30;
    point2.y = 10;
    point2.z = 10;

    Point point3;
    point3.x = 10;
    point3.y = 30;
    point3.z = 10;

    Point point4;
    point4.x = 30;
    point4.y = 30;
    point4.z = 10;

    Point point5;
    point5.x = 10;
    point5.y = 10;
    point5.z = 30;

    Point point6;
    point6.x = 30;
    point6.y = 10;
    point6.z = 30;

    Point point7;
    point7.x = 10;
    point7.y = 30;
    point7.z = 30;

    Point point8;
    point8.x = 30;
    point8.y = 30;
    point8.z = 30;

    Line line1;
    line1.points[0] = point1;
    line1.points[1] = point2;

    Line line2;
    line2.points[0] = point2;
    line2.points[1] = point4;

    Line line3;
    line3.points[0] = point4;
    line3.points[1] = point3;

    Line line4;
    line4.points[0] = point3;
    line4.points[1] = point1;

    Line line5;
    line5.points[0] = point5;
    line5.points[1] = point6;

    Line line6;
    line6.points[0] = point6;
    line6.points[1] = point8;

    Line line7;
    line7.points[0] = point8;
    line7.points[1] = point7;

    Line line8;
    line8.points[0] = point7;
    line8.points[1] = point5;

    Line line9;
    line9.points[0] = point5;
    line9.points[1] = point1;

    Line line10;
    line10.points[0] = point6;
    line10.points[1] = point2;

    Line line11;
    line11.points[0] = point7;
    line11.points[1] = point3;

    Line line12;
    line12.points[0] = point8;
    line12.points[1] = point4;
