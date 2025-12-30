// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;36m青色垃圾龍[2;37;0m[2;37;0m", ({"xlqxaa"}));        
        set("gender", "女性");                
        set("long", "都是很醜[2;37;0m
它是路飛的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xlqxa");
        set("owner_name", "路飛");
        set_temp("owner", "xlqxa");
        set_temp("owner_name", "路飛");
        ::setup();
}
