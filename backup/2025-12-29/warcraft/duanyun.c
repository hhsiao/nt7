// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m赤兔馬[2;37;0m[2;37;0m", ({"duanyunride"}));        
        set("gender", "男性");                
        set("long", "這是一匹千年難得一遇的寶馬[2;37;0m
它是段雲的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "duanyun");
        set("owner_name", "段雲");
        set_temp("owner", "duanyun");
        set_temp("owner_name", "段雲");
        ::setup();
}
