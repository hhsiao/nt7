// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m[41;1m日本充氣娃娃[1;37m[41;1m[2;37;0m[2;37;0m", ({"niao"}));        
        set("gender", "男性");                
        set("long", "她膚如凝脂，眉目如畫，風情萬種，楚楚動人。當真是我見猶憐！	[2;37;0m
它是血海飄香的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dupengc");
        set("owner_name", "血海飄香");
        set_temp("owner", "dupengc");
        set_temp("owner_name", "血海飄香");
        ::setup();
}
