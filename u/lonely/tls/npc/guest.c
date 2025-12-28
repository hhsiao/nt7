// guest.c 進香客

inherit NPC;

string *first_name = ({ "趙","孫","李","周","吳","鄭","王","張","陳","柳","風","劉","林", }); 
string *man_name_words = ({ "青","順","風","峰","建","明","銘","戰","冠", });
string *woman_name_words = ({ "蓮","燕","娜","妮","芳","香","仙","芊","芡", });
string *xing = ({ "男性","女性", });

void create()
{
	int age;
	string name,xingbie;
		age = 20 + random(40);
		xingbie = xing[random(sizeof(xing))];
        name = first_name[random(sizeof(first_name))];
        if (xingbie !="男性")
		{
		name += woman_name_words[random(sizeof(woman_name_words))]; 
        } else { name += man_name_words[random(sizeof(man_name_words))]; }
 

	set_name(name, ({ "guest" }));
    set("title", "進香客");
    set("gender", xingbie);
	set("age", age);
	set_skill("unarmed", random(40));
	set_skill("dodge", random(40));
	set("apply/attack", 15);
	set("apply/defense", 15);
	set("apply/damage", 5);
	set("combat_exp", 150+age*10);
	set("shen_type", 1);
		 set("chat_chance", 2);

	 set("chat_msg", ({
	 "進香客低聲吟道：一切有為法，如夢幻泡影\n",
	 "進香客閉目合什：南無阿彌陀佛 \n",
	 "進香客朗聲說道：有法無法，皆是虛妄\n",
	 "進香客說道：南無救苦救難廣大靈感觀世音菩薩！\n",
	     (: random_move :)
        }) );
	setup();
	add_money("coin", 10+age/10);
}
	
