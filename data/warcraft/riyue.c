// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("日月鏡[2;37;0m[2;37;0m", ({"riyuejing"}));        
        set("gender", "男性");                
        set("long", "日月鏡[2;37;0m
它是凸透鏡的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "riyue");
        set("owner_name", "凸透鏡");
        set_temp("owner", "riyue");
        set_temp("owner_name", "凸透鏡");
        ::setup();
}
