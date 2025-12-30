// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛雲[2;37;0m[2;37;0m", ({"flycloud"}));        
        set("gender", "男性");                
        set("long", "無[2;37;0m
它是謝閒的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "tofo");
        set("owner_name", "謝閒");
        set_temp("owner", "tofo");
        set_temp("owner_name", "謝閒");
        ::setup();
}
