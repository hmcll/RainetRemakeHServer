#include "InitializePieces.h"
#include "Enums.h"
#include "RSData_Map.h"
#include "RSData_Command.h"
void CA_InitializePieces::Initialize(EPlayerType owner, void* meta)
{}

bool CA_InitializePieces::CanDo(RSData_Command& command, RSData_Map& map)
{
	if (map.GetGameState() != EGameState::Initialization){
		return false;
	}
	if (command.Player != command.Player & 0x01){
		return false;
	}
	return  true;
	
}

bool CA_InitializePieces::Do(RSData_Command& command, RSData_Map& map, std::vector<uint8_t>& outputBuffer)
{
	RSData_Player player = map.getPlayer(command.Player == EPlayerType::Player1);

	for (int i = 0; i < MAP_SIZE; i++)
	{
		player.pieces[i].Type = EPieceType(command.Data.PieceSetup.setup & 1 << i);
	}
	return true;
}

bool CA_InitializePieces::Block(RSData_Command& command, RSData_Map& map)
{
	return false;
}

RS_CommandAction* CreateInitializePieces() {
	static CA_InitializePieces instance = CA_InitializePieces();
	return &instance;
}

RS_CommandActionCreateFunction createInitializePieceFunction = RS_CommandActionCreateFunction(EActionType::LineBoost, &CreateInitializePieces);