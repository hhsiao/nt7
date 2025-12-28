// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[46m[1;37m九尾狐狸精[2;37;0m[2;37;0m", ({"foxtrel"}));        
        set("gender", "女性");                
        set("long", "一隻善解人意，溫馨漂亮的狐狸精。[2;37;0m
它是紅蓮老祖的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "redl");
        set("owner_name", "紅蓮老祖");
        set_temp("owner", "redl");
        set_temp("owner_name", "紅蓮老祖");
        ::setup();
}
