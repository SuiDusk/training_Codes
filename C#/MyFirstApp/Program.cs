Console.WriteLine("Hello, World!");
int[] scores = new int[3] { 90, 85, 88 };
Console.WriteLine(scores[0]); // 输出 90（索引从0开始）

Point p1 = new Point() { X = 10, Y = 20 };
Point p2 = p1;
Console.WriteLine(p1.X + "\n");//输出p1.X并换两次行
Console.WriteLine(p1.Y);//输出p1.Y并换行
Console.WriteLine();//输出换行
p2.X += 10; p2.Y += 10;
Console.WriteLine(p2.X + " " + p2.Y);//输出p2.X和空格
Console.WriteLine(p1.X + " " + p1.Y);//输出p1.X和空格

//Person p3 = new Person("张三");
Person p3 = new Person { Name = "张三" };
Person p4 = p3;
Console.WriteLine(p3.Name);
p4.Name = "李四";
Console.WriteLine(p3.Name);

Season current = Season.Summer;
Console.WriteLine(current);

enum Season { Spring, Summer, Autumn, Winter };
class Person
{
    public required string Name { get; set; }//添加required来确保初始化时必须被赋值
    // public Person(string name)
    // {
    //     Name = name;
    // }
}

struct Point { public int X; public int Y; }