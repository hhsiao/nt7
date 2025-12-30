// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("無痕[2;37;0m[2;37;0m", ({"wuhen"}));        
        set("gender", "女性");                
        set("long", "無痕[2;37;0m
它是東方飄玲的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "piaoling");
        set("owner_name", "東方飄玲");
        set_temp("owner", "piaoling");
        set_temp("owner_name", "東方飄玲");
        ::setup();
}
