// 構造体の宣言2通り

struct		s_person1
{
	char	*name;
	char	sex;
	int		age;
	char	*addrs;
	char	*job;
};

// typedef
typedef struct person
{
	char	*name;
	char	sex;
	int		age;
	char	*addrs;
	char	*job;
}			t_person2;

// 初期化

// 「typedef」句を使った「構造体名」型の初期化にはstruct不要
// 構造体の初期化について全メンバへの一括代入は実体の宣言時のみ可能

// 構造体のメンバは、実体からドット演算子(「.」)を使って呼び出し

// 一括代入用の関数
t_person2	init(char *name, char sex, int age, char *addrs, char *job)
{
	t_person2	p2;

	p2.name = name;
	p2.sex = sex;
	p2.age = age;
	p2.addrs = addrs;
	p2.job = job;
	return (p2);
}

int	main(void)
{
	// 構造体の実体を生成
	struct s_person1	tanaka;
	tanaka.name = "T.Tanaka";
	tanaka.sex = 'm';
	tanaka.age = 30;
	tanaka.addrs = "Tokyo";
	tanaka.job = "teacher";
	printf("%sは%d歳で、%sで%sをしています\n", tanaka.name, tanaka.age, tanaka.addrs,
		tanaka.job);

	// 構造体の実体の生成と一括初期化
	t_person2 sato = {"S.Sato", 'f', 25, "Osaka", "nurse"};
	/* error: expected expression before '{' token
    sato = {"S.Sato", 'f', 25, "Osaka", "nurse"};
    */
	printf("%sは%d歳で、%sで%sをしています\n", sato.name, sato.age, sato.addrs, sato.job);

	// 関数で一括代入
	sato = init("K.Sato", 'm', 35, "Nagoya", "doctor");
	printf("%sは%d歳で、%sで%sをしています\n", sato.name, sato.age, sato.addrs, sato.job);

	return (0);
}
