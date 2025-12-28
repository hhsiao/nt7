// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m像閃電一樣[2;37;0m[2;37;0m", ({"like_lighting"}));        
        set("gender", "男性");                
        set("long", "$HIW$像閃電一樣[2;37;0m
它是帝林的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dilin");
        set("owner_name", "帝林");
        set_temp("owner", "dilin");
        set_temp("owner_name", "帝林");
        ::setup();
}
