
#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("鍾槌", ({ "zhong chui","chui" }) );
	set_weight(3000);
		set("unit", "把");
		set("long", "這是一把沉甸甸的鐘槌，竟然是用鐵木製成，堅硬異常。\n");
		set("value", 3);
		set("material", "iron");
		set("wield_msg", "$N拿出一把$n，握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");

	init_hammer(15);
	setup();
}
