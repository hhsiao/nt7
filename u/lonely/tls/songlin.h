int valid_leave(object me, string dir)
{
        if (dir == "west")
         me->add_temp("mark/step",1);
        if (dir == "south")
          me->add_temp("mark/steps",1);
        if (dir == "east")
          me->add_temp("mark/step",-1); 
        if (dir == "north")
          me->add_temp("mark/steps",-1);

        if (me->query_temp("mark/step") == -6&&me->query_temp("mark/steps") == -7&&random(me->query("int"))>20)
         {
            me->move(__DIR__"xdt");
            me->delete_temp("mark/steps");
            me->delete_temp("mark/step");
             return notify_fail("你正走著，透過樹枝，隱約發現前面有片空地，你撥開樹枝鑽了過去。\n");
         }  
        if (me->query_temp("mark/steps") == -6&&me->query_temp("mark/step") == 5)
         {
            me->move(__DIR__"lsy");
            me->delete_temp("mark/steps");
            me->delete_temp("mark/step");
             return notify_fail("你正走著，突然發現前面有一間小木屋,你不由的走了過去。\n");
         }  
     if (me->query_temp("mark/steps") > 10)
            {  
           me->move(__DIR__"road7");
           me->delete_temp("mark/steps");
           me->delete_temp("mark/step");
 return notify_fail("你筋疲力盡,終於走出了松林。\n");

        }
           
        return ::valid_leave(me, dir);
}

