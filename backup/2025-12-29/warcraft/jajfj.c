// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白虎[2;37;0m[2;37;0m", ({"atx"}));        
        set("gender", "男性");                
        set("long", "白虎[2;37;0m
它是中解決的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "jajfj");
        set("owner_name", "中解決");
        set_temp("owner", "jajfj");
        set_temp("owner_name", "中解決");
        ::setup();
}
