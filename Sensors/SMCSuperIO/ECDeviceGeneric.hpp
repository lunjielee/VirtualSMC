//
//  ECDeviceGeneric.hpp
//  SMCSuperIO
//
//  Copyright © 2021 vit9696. All rights reserved.
//

#ifndef ECDeviceGeneric_hpp
#define ECDeviceGeneric_hpp

#include "SuperIODevice.hpp"
#include "ECDevice.hpp"

namespace EC {

	class ECDeviceGeneric : public ECDevice {
		const char *modelName {"Generic EC"};
		IORegistryEntry *device {nullptr};

		uint32_t tachometerCount {1};

		static constexpr uint32_t MaxTachometerCount {5};

		struct Tachometer {
			const char *name;
			uint32_t addr;
			uint8_t size;
			bool bigEndian;
		};

		Tachometer tachometers[MaxTachometerCount] {};

	protected:
		const char* getModelName() override;

		uint8_t getTachometerCount() override;
		uint16_t updateTachometer(uint8_t index) override;
		const char* getTachometerName(uint8_t index) override;

		uint8_t getVoltageCount() override;
		float updateVoltage(uint8_t index) override;
		const char* getVoltageName(uint8_t index) override;

		/**
		 *  Ctor
		 */
		ECDeviceGeneric(IORegistryEntry *lpc);

	public:
		/**
		 *  Device factory
		 */
		static ECDevice* detect(SMCSuperIO* sio, const char *name, IORegistryEntry *lpc);
	};
}

#endif /* ECDeviceGeneric_hpp */
