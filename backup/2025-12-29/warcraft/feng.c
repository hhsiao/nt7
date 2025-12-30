// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白狐[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "女性");                
        set("long", "白[2;37;0m
它是胡鐵花的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "feng");
        set("owner_name", "胡鐵花");
        set_temp("owner", "feng");
        set_temp("owner_name", "胡鐵花");
        ::setup();
}
