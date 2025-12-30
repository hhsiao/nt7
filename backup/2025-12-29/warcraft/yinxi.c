// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m[5m御[1;34m[5m風[1;31m[5m青[1;33m[5m龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "飛雪連天射白鹿，笑書神俠倚碧鴛。[2;37;0m
它是音曦的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "yinxi");
        set("owner_name", "音曦");
        set_temp("owner", "yinxi");
        set_temp("owner_name", "音曦");
        ::setup();
}
