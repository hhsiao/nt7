// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[30m黑[2;37;0m[2;37;0m", ({"hql"}));        
        set("gender", "女性");                
        set("long", "黑[2;37;0m
它是將就愛的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "jja");
        set("owner_name", "將就愛");
        set_temp("owner", "jja");
        set_temp("owner_name", "將就愛");
        ::setup();
}
