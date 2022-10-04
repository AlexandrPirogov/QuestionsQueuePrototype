#pragma once
#include <memory>
#include <string>
#include <map>
#include <list>

class Question
{
	short correctAnswer;
	std::string question;
	std::map<int, std::string> possibleAnswers;
public:
	Question() = delete;
	Question(std::string question, std::map<int, std::string> possibleAnswers, short correctAnswer)
		: possibleAnswers(possibleAnswers), question(question), correctAnswer(correctAnswer) {};

	inline const std::string whatQuestion()
	{
		return question;
	}

	inline const std::map<int, std::string> whatPossibleAnswers()
	{
		return possibleAnswers;
	}

	inline const short whatCorrectAnswer()
	{
		return correctAnswer;
	}
};

class QuestionQueue
{
	short add_status;
	short answer_status;
	std::list <std::shared_ptr<Question>> questions;
public:

	short const ADD_STATUS_NIL = -1;
	short const ADD_STATUS_OK = 0;

	short const ANSWER_STATUS_NIL = -1;
	short const ANSWER_STATUS_OK = 0;
	short const ANSWER_STATUS_INCORRECT = 1;
	short const ANSWER_STATUS_ERR = 2;

	QuestionQueue()
	{
		add_status = ADD_STATUS_NIL;
		answer_status = ANSWER_STATUS_NIL;
	};

	inline void emplaceBack(std::shared_ptr<Question>& question) noexcept
	{
		questions.emplace_back(std::move(question));
		add_status = ADD_STATUS_OK;
	}

	inline std::shared_ptr<Question> currentQuestion()
	{
		std::shared_ptr<Question> currentQ = *questions.begin();
		return currentQ;
	}
	
	inline void answerToQuestion(short ans)
	{
		std::shared_ptr<Question> currentQ = *questions.begin();
		currentQ->whatCorrectAnswer() == ans ? answer_status = ANSWER_STATUS_OK : answer_status = ANSWER_STATUS_INCORRECT;
		if(answer_status == ANSWER_STATUS_OK)
			questions.erase(questions.begin());
	}

	inline bool isNext() noexcept
	{
		return questions.size() > 0;
	}

	inline const size_t size() noexcept
	{
		return questions.size();
	}

	inline const short addStatus() noexcept
	{
		return add_status;
	}

	inline const short answerStatus() noexcept
	{
		return answer_status;
	}

};

