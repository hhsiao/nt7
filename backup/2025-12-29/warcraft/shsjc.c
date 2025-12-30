// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大白虎[2;37;0m[2;37;0m", ({"wtiger"}));        
        set("gender", "男性");                
        set("long", "大白虎[2;37;0m
它是小貴子的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "shsjc");
        set("owner_name", "小貴子");
        set_temp("owner", "shsjc");
        set_temp("owner_name", "小貴子");
        ::setup();
}
