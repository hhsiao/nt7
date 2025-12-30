// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("張揚[2;37;0m[2;37;0m", ({"zhangyangb"}));        
        set("gender", "男性");                
        set("long", "張揚[2;37;0m
它是小紅顏的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "forreda");
        set("owner_name", "小紅顏");
        set_temp("owner", "forreda");
        set_temp("owner_name", "小紅顏");
        ::setup();
}
