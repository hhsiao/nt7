// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m玻璃[2;37;0m[2;37;0m", ({"vetro"}));        
        set("gender", "男性");                
        set("long", "一塊玻璃[2;37;0m
它是淨琉璃的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "glass");
        set("owner_name", "淨琉璃");
        set_temp("owner", "glass");
        set_temp("owner_name", "淨琉璃");
        ::setup();
}
