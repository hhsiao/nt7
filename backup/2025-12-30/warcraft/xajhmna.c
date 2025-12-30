// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;37m母白虎[2;37;0m[2;37;0m", ({"mulaohu"}));        
        set("gender", "女性");                
        set("long", "白虎，母[2;37;0m
它是時間至上的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "xajhmna");
        set("owner_name", "時間至上");
        set_temp("owner", "xajhmna");
        set_temp("owner_name", "時間至上");
        ::setup();
}
