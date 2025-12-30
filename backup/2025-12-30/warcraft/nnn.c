// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[30m記錄點[2;37;0m[2;37;0m", ({"teak_save"}));        
        set("gender", "男性");                
        set("long", "$BLK$記錄點[2;37;0m
它是影邪的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "nnn");
        set("owner_name", "影邪");
        set_temp("owner", "nnn");
        set_temp("owner_name", "影邪");
        ::setup();
}
