// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m洪騎龍[2;37;0m[2;37;0m", ({"hql"}));        
        set("gender", "女性");                
        set("long", "洪主公騎的母龍[2;37;0m
它是洪主公的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "daxiakea");
        set("owner_name", "洪主公");
        set_temp("owner", "daxiakea");
        set_temp("owner_name", "洪主公");
        ::setup();
}
