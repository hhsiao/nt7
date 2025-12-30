// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("神仙龍[2;37;0m[2;37;0m", ({"shengou"}));        
        set("gender", "男性");                
        set("long", "神仙龍[2;37;0m
它是龍貳的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "sghdxb");
        set("owner_name", "龍貳");
        set_temp("owner", "sghdxb");
        set_temp("owner_name", "龍貳");
        ::setup();
}
