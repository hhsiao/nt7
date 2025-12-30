// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;36m龍貓[2;37;0m[2;37;0m", ({"longlong"}));        
        set("gender", "女性");                
        set("long", "說說[2;37;0m
它是亂舞的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lookme");
        set("owner_name", "亂舞");
        set_temp("owner", "lookme");
        set_temp("owner_name", "亂舞");
        ::setup();
}
