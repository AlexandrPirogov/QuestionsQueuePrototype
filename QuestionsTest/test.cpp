#include "pch.h"
#include "./../QuestionGame/queue_question.h"
#include <memory>
#include <string>
#include <map>

namespace QueueTests
{
	std::shared_ptr<Question> createQuestion()
	{
		std::string quesStr = "Question?";
		std::map<int, std::string> answers = { {1, "1"}, {2, "2"}, {3, "3"} };
		int correct = 1;
		std::shared_ptr<Question> ques = std::make_shared<Question>(quesStr, answers, correct);
		assert(ques->whatCorrectAnswer() == correct);
		assert(ques->whatQuestion()  == quesStr);
		assert(ques->whatPossibleAnswers() == answers);
		return ques;
	}

	TEST(TestCaseName, TestName) {
		EXPECT_EQ(1, 1);
		EXPECT_TRUE(true);
	}

	TEST(QuestionTests, CreatingTest) {
		std::shared_ptr<Question> question = createQuestion();
	}

	TEST(QueueTests, CreatingQueue)
	{
		std::unique_ptr<QuestionQueue> queue = std::make_unique<QuestionQueue>();
		ASSERT_TRUE(queue->size() == 0);
		ASSERT_TRUE(queue->addStatus() == queue->ADD_STATUS_NIL);
		ASSERT_TRUE(queue->answerStatus() == queue->ANSWER_STATUS_NIL);
	}


	//TCR
	TEST(QuestionTest, FillingQueue)
	{
		std::unique_ptr<QuestionQueue> queue = std::make_unique<QuestionQueue>();
		std::shared_ptr<Question> question = createQuestion();
		queue->emplaceBack(question);
		ASSERT_TRUE(queue->addStatus() == queue->ADD_STATUS_OK && queue->size() > 0);
	}
}



