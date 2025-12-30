// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m白玉[1;33m小麒麟[2;37;0m[2;37;0m", ({"yuqilin"}));        
        set("gender", "男性");                
        set("long", "$HIW$白玉$HIY$小麒麟[2;37;0m
它是慕容博復的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "hskbc");
        set("owner_name", "慕容博復");
        set_temp("owner", "hskbc");
        set_temp("owner_name", "慕容博復");
        ::setup();
}
