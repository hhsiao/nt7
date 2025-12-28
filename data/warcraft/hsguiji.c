// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("寶馬[2;37;0m[2;37;0m", ({"baoma"}));        
        set("gender", "男性");                
        set("long", "我的寶馬[2;37;0m
它是亢龍有悔的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "hsguiji");
        set("owner_name", "亢龍有悔");
        set_temp("owner", "hsguiji");
        set_temp("owner_name", "亢龍有悔");
        ::setup();
}
