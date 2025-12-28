// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m窮[1;31m奇[2;37;0m[2;37;0m", ({"oxo"}));        
        set("gender", "女性");                
        set("long", "窮奇狀如虎，有翼，食人從首始，所食被髮，在□犬北。[2;37;0m
它是拳廿七的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "oip");
        set("owner_name", "拳廿七");
        set_temp("owner", "oip");
        set_temp("owner_name", "拳廿七");
        ::setup();
}
