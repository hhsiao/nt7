// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;35m陳家洛[2;37;0m[2;37;0m", ({"jialuo"}));        
        set("gender", "女性");                
        set("long", "$BLINK$$HIM$陳家洛[2;37;0m
它是紅花郎的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "honghua");
        set("owner_name", "紅花郎");
        set_temp("owner", "honghua");
        set_temp("owner_name", "紅花郎");
        ::setup();
}
